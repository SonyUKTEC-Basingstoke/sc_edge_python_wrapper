#include <pybind11/pybind11.h>

#include "sc_api.h"

using namespace std;
using namespace pybind11;

static void sc_proc_dnn_output_callback(const sc_proc_dnn_output_t *p_dnn_proc_result)
{
    (void) p_dnn_proc_result;
}

static void sc_proc_raw_output_callback(const sc_proc_raw_output_t *p_raw_proc_result)
{
    (void) p_raw_proc_result;
}


sc_app_config_t* create_app_config(){
    return NULL;
}

sc_dnn_config_t* create_dnn_config(){
    return NULL;
}

int sc_initialise(sc_app_config_t* app_config){
    return sc_init(app_config);
}

int sc_opens(){
    return sc_open();
}

int sc_loads(sc_dnn_config_t* dnn_config){
    return sc_load(dnn_config);
}

int sc_loads_dwp(){
    return sc_load_dwp();
}

int sc_starts(){
    return sc_start(E_START_MODE_RAW_ONLY, sc_proc_dnn_output_callback, sc_proc_raw_output_callback);
}


PYBIND11_MODULE(sc_wrapper, m){
    m.doc() = "sc_wrapper";
    m.def("sc_init", &sc_initialise, "initialise IMX");
    m.def("sc_open", &sc_opens, "open imx file");
    m.def("sc_load", &sc_loads, "load imx file");
    m.def("sc_load_dwp", &sc_loads_dwp, "load dwp");
    m.def("sc_start", &sc_starts, "start camera");
    m.def("create_app_config", &create_app_config, "create sc_app_config object");
    m.def("create_dnn_config", &create_dnn_config, "create dnn_config");
    class_<sc_app_config_t>(m, "sc_app_config_t");
    class_<sc_dnn_config_t>(m, "sc_dnn_config_t");
}
