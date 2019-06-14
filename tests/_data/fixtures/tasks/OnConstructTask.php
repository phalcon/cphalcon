<?php

class OnConstructTask extends \Phalcon\CLI\Task
{
    public $onConstructExecuted = false;

    public function onConstruct()
    {
        $this->onConstructExecuted = true;
    }
}
