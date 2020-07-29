<?php
declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Session;

use Phalcon\Session\Adapter\Noop;
use Phalcon\Session\Manager;

class NoopManager extends Manager
{
    public function __construct(array $options = [])
    {
        $this->setAdapter(new Noop());
        parent::__construct($options);
    }
}
