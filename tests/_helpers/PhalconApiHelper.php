<?php
namespace Codeception\Module;


use Codeception\Codecept;
use Phalcon\Mvc\Router;

class PhalconApiHelper extends \Codeception\Module {

    /**
     * @var \Codeception\TestCase
     */
    protected $test;


    /**
     * @var \Phalcon\DI
     */
    public $di;
    
    public function _initialize()
    {

    }

    public function _before(\Codeception\TestCase $test)
    {
        $this->test = $test;
        $this->isExtensionLoaded('phalcon');
        
        \Phalcon\DI::reset();

        // Instantiate a new DI container
        $this->di = new \Phalcon\DI();

        // Set the URL
        $this->di->set('url', function () {
                $url = new \Phalcon\Mvc\Url();
                $url->setBaseUri('/');
                return $url;
            }
        );

        $this->di->set('escaper', function () {
                return new \Phalcon\Escaper();
            }
        );
        
    }

    public function getDi()
    {
        return $this->di;

    }

    public function addService($name, $function)
    {
        $this->di->set($name, $function);
    }

    public function getService($name)
    {
        return $this->di->get($name);
    }

    public function withDi($service)
    {
        if (!method_exists($service, 'setDI')) {
            throw new \RuntimeException(get_class($service)." have no `setDI` method as expected");
        }
        $service->setDI($this->di);
        return $service;

    }

    protected function isExtensionLoaded($extension)
    {
        if (!extension_loaded($extension)) {
            $this->test->markTestSkipped("Warning: {$extension} extension is not loaded");
        }
    }


    
    


}