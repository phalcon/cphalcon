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

    public function helloAction($params = array())
    {
        $world  = @$params[0] ?: "";
        $symbol = @$params[1] ?: "!";

        return "Hello " . $world . $symbol;
    }
}
