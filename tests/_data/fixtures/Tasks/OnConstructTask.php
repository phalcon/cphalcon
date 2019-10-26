<?php

namespace Phalcon\Test\Fixtures\Tasks;

class OnConstructTask extends \Phalcon\Cli\Task
{
    public $onConstructExecuted = false;

    public function onConstruct()
    {
        $this->onConstructExecuted = true;
    }
}
