<?php

class ExceptionController extends \Phalcon\Mvc\Controller
{
    public function indexAction()
    {
        throw new \Exception('whups bad controller');
    }

    public function secondAction()
    {
        return 'I should be displayed';
    }
}
