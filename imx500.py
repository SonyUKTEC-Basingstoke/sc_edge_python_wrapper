from sc_wrapper import *


class IMX500():
    #track if there is an instance
    _instance = None
    
    
    #we check if there is not an instance and then create a new instance
    #if an instance exists, do nothing
    def __new__(cls):
        if cls.instance is None:
            cls._instance = super(IMX500, cls).__new__(cls)
        return cls._instance
    
    #start up the imx camera, this function acts as a shortcut by running 
    #several functions in a row
    def start(self):
        app_config = create_app_config()
        dnn_config = create_dnn_config()
        sc_init(app_config)
        sc_open()
        sc_load(dnn_config)
        sc_load_dwp()
        sc_start()

imx500 = IMX500.create_instance()
imx500.start()
