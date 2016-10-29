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
        $world  = isset($params[0]) ? $params[0] : "";
        $symbol = isset($params[1]) ? $params[1] : "!";

        return "Hello " . $world . $symbol;
    }
}
