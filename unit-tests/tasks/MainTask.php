<?php

class MainTask extends \Phalcon\CLI\Task
{

    public function mainAction()
    {
        return "mainAction";
    }

    public function requestRegistryAction()
    {
        return $this->di['registry']->data;
    }

    public function helloAction($world = "", $symbol = "!")
    {
        return "Hello " . $world . $symbol;
    }
}
