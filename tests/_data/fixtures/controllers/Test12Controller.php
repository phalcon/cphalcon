<?php

class Test12Controller extends \Phalcon\Mvc\Controller
{
    public function afterBinding()
    {
        return false;
    }

    public function indexAction()
    {
        return 'test';
    }
}
