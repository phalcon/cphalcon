<?php

class Issue787Task extends \Phalcon\CLI\Task
{
    static $output = '';

    public function beforeExecuteRoute()
    {
        $this->dispatcher;
        $this->dispatcher;
        self::$output .= "beforeExecuteRoute\n";
        return true;
    }

    public function initialize()
    {
        self::$output .= "initialize\n";
    }

    public function mainAction()
    {
    }
}
