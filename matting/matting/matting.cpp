#include <iostream>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include<boost/python/tuple.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include<Eigen/SparseLU>
#include<Eigen/IterativeLinearSolvers>
#include <Eigen/SparseCore>
#include <Eigen/Core>
#include <Eigen/Dense>
//#include <unsupported/Eigen/IterativeSolvers>

typedef Eigen::SparseMatrix<double> SpMat;
typedef Eigen::Triplet<double> T;

using namespace Eigen;
using namespace std;
using namespace boost;
namespace bp = boost::python;
namespace bn = boost::python::numpy;
//using namespace boost::python::numpy;

class Matting():
{
	bn::ndarray matting():
	{

	}
}

bn::ndarray my_add(bn::ndarray& a_array, bn::ndarray& b_array)
{	
	bn::dtype dt = bn::dtype::get_builtin<int>();
	a_array = a_array.astype(dt);
	b_array = b_array.astype(dt);

	const int* a = reinterpret_cast<const int*>(a_array.get_data());
	const bp::tuple &shape = bp::extract<bp::tuple>(a_array.attr("shape"));
	int h = bp::extract<int>(shape[0]);
	int w = bp::extract<int>(shape[1]);

	const int* b = reinterpret_cast<const int*>(b_array.get_data());

	int* c_list = new int[h]();
	for (int i = 0; i < h; i++)
	{
		c_list[i] = *(a+i) + *(b+i);
	}

	bn::ndarray c_array = bn::from_data(c_list, dt, bp::make_tuple(h), bp::make_tuple(sizeof(int)), bp::object());
	//delete[] c_list;

	return c_array;
}

BOOST_PYTHON_MODULE(matting)
{
	Py_Initialize();
	bn::initialize();
	bp::def("my_add", &my_add);
}