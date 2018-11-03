<?php

class MyMiddlewareStop implements Phalcon\Mvc\Micro\MiddlewareInterface
{
    protected $_number = 0;

    public function call(\Phalcon\Mvc\Micro $application)
    {
        $application->stop();
        $this->_number++;
    }

    public function getNumber()
    {
        return $this->_number;
    }
}
