<?php

class MyMiddleware implements Phalcon\Mvc\Micro\MiddlewareInterface
{
    protected $_number = 0;

    public function call(\Phalcon\Mvc\Micro $application)
    {
        $this->_number++;
    }

    public function getNumber()
    {
        return $this->_number;
    }
}
