<?php

class SplClassloader {
    private $_appFolders = ['Base', 'Controllers', 'Models'];
    private $_fileExtension = '.php';
    private $_namespace;
    private $_includePath;
    private $_namespaceSeparator = '\\';

    /**
     * @param string $ns
     * @param string $includePath
     */
    public function __construct($ns = null, $includePath = null)
    {
        $this->_namespace = $ns;
        $this->_includePath = $includePath;
    }

    /**
     * Installs this class loader on the SPL autoload stack.
     */
    public function registerAutoloader()
    {
        spl_autoload_register(array($this, 'autoloader'));
    }

    /**
     * Loads the given class or interface.
     *
     * @return void
     */
    public function autoloader()
    {
        foreach ($this->_appFolders as $folder) {
            $files = scandir($this->_namespace . DIRECTORY_SEPARATOR . $folder);

            foreach($files as $file) {
                $fileName = $this->_namespace . DIRECTORY_SEPARATOR . $folder . DIRECTORY_SEPARATOR . $file;

                if (file_exists($fileName) && filetype($fileName) == 'file') {
                    // echo "<pre>";
                    // var_dump($fileName);
                    // echo "</pre>";
                    require_once $fileName;
                }
            }
        }
    }
}