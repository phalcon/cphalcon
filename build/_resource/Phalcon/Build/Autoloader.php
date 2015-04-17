<?php
namespace Phalcon\Build;

class Autoloader
{
    /**
     * @var string
     */
    protected $baseDir;

    /**
     * @param string $baseDir Base directory for all script source files
     */
    public function __construct($baseDir)
    {
        $this->baseDir = str_replace('\\', '/', $baseDir);
    }

    /**
     * Add autoloader to autoloaders queue
     */
    public function register()
    {
        spl_autoload_register(array($this, 'autoload'));
    }

    /**
     * This function is not intended for public calls. It is public just because in PHP 5.3 it is not possible
     * to create a callable to a protected method, which will be called outside of the class.
     *
     * @param $className
     */
    public function autoload($className)
    {
        $className = ltrim($className, '\\');
        $fileName = $this->baseDir . '/' . str_replace(array('_', '\\'), '/', $className) . '.php';
        if (file_exists($fileName)) { // If not found, then let any subsequent autoloader load the class file
            require($fileName);
        }
    }
}
