#ifndef DYROS_JET_MODEL_H
#define DYROS_JET_MODEL_H

#include <string>
#include <map>

#include <ros/ros.h>
#include <ros/package.h>
#include <rbdl/rbdl.h>
#include <rbdl/addons/urdfreader/urdfreader.h>
#include "math_type_define.h"


namespace dyros_jet_controller
{

class DyrosJetModel
{
public:
  DyrosJetModel();

  enum EndEffector : unsigned int {
    EE_LEFT_FOOT, EE_RIGHT_FOOT,
    EE_LEFT_HAND, EE_RIGHT_HAND};

  static constexpr size_t HW_TOTAL_DOF = 32;
  static constexpr size_t MODEL_DOF = 28;
  static constexpr size_t MODEL_DOF_VJOINT = 34;


  static const std::string JOINT_NAME[HW_TOTAL_DOF];
  static const int JOINT_ID[HW_TOTAL_DOF];

  static constexpr const char* EE_NAME[4] =
      {"L_AnkleRoll_Link", "R_AnkleRoll_Link",
       "L_HandYaw_Link", "R_HandYaw_Link" };

  unsigned int end_effector_id_[4];
  const unsigned int joint_start_index_[4];

  void test();

  std::map<std::string, size_t> joint_name_map_;
  size_t getIndex(const std::string& joint_name)
  {
    return joint_name_map_[joint_name];
  }
  // Calc Jacobian, Transformation
  void updateKinematics(const Eigen::VectorXd &q);

  void updateSensorData(const Eigen::Vector6d &r_ft, const Eigen::Vector6d &l_ft, const Eigen::Vector12d &q_ext);

  void getTransformEndEffector(EndEffector ee, Eigen::Isometry3d* transform_matrix);
  void getTransformEndEffector(EndEffector ee, Eigen::Vector3d* position, Eigen::Matrix3d* rotation);

  void getTransformEndEffector(EndEffector ee, const Eigen::VectorXd& q, bool update_kinematics,
                                  Eigen::Vector3d* position, Eigen::Matrix3d* rotation);


  void getJacobianMatrix6DoF(EndEffector ee, Eigen::Matrix<double, 6, 6> *jacobian);
  void getJacobianMatrix7DoF(EndEffector ee, Eigen::Matrix<double, 6, 7> *jacobian);
  void getJacobianMatrix18DoF(EndEffector ee, Eigen::Matrix<double, 6, 18> *jacobian);

  void getCenterOfMassPosition(Eigen::Vector3d* position);

  void getInertiaMatrix34DoF(Eigen::Matrix<double, 34, 34> *inertia);
  void getInertiaMatrix18DoF(Eigen::Matrix<double, 18, 18> *leg_inertia);


  const Eigen::Vector12d& getCurrentExtencoder(){ return q_ext_; }
  const Eigen::Isometry3d& getCurrentTrasmfrom(EndEffector ee) { return currnet_transform_[ee]; }
  const Eigen::Matrix<double, 6, 6>& getLegJacobian(EndEffector ee) { return leg_jacobian_[ee]; }
  const Eigen::Matrix<double, 6, 7>& getArmJacobian(EndEffector ee) { return arm_jacobian_[ee-2]; }
  const Eigen::Matrix<double, 6, 18>& getLegWithVLinkJacobian(EndEffector ee) { return leg_with_vlink_jacobian_[ee]; }
  const Eigen::Vector3d& getCurrentCom(){ return com_;}
  const Eigen::Vector6d& getRightFootForce() {return r_ft_wrench_;}
  const Eigen::Vector6d& getLeftFootForce() {return l_ft_wrench_;}
  const Eigen::Matrix<double, 18, 18>& getLegInertia() { return leg_inertia_mat_; }
  const Eigen::Matrix<double, 34, 34>& getFullInertia() { return full_inertia_mat_; }

private:
  RigidBodyDynamics::Model model_;

  Eigen::Vector28d q_;
  Eigen::Matrix<double, 34, 1> q_virtual_;
  Eigen::Vector12d q_ext_;
  Eigen::Vector12d extencoder_offset_;
  bool extencoder_init_flag_;

  Eigen::Vector3d base_position_;

  Eigen::Isometry3d currnet_transform_[4];

  Eigen::Matrix<double, 6, 6> leg_jacobian_[2];
  Eigen::Matrix<double, 6, 7> arm_jacobian_[2];
  Eigen::Matrix<double, 6, 18> leg_with_vlink_jacobian_[2];

  Eigen::Matrix<double, 34, 34> full_inertia_mat_;
  Eigen::Matrix<double, 18, 18> leg_inertia_mat_;

  Eigen::Vector3d com_;

  Eigen::Vector6d r_ft_wrench_;
  Eigen::Vector6d l_ft_wrench_;

};

typedef Eigen::Matrix<double, DyrosJetModel::HW_TOTAL_DOF, 1> VectorQd;


}
#endif // DYROS_JET_MODEL_H
