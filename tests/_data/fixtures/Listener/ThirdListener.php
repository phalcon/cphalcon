<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Listener;

use ComponentX;
use Phalcon\Events\Event;
use Phalcon\Test\Unit\Events\ManagerTest;

class ThirdListener
{
    /** @var  ManagerTest */
    protected $testCase;

    protected $before = 0;

    protected $after = 0;

    public function __construct()
    {
        include_once PATH_DATA . 'events/ComponentX.php';
    }

    public function setTestCase(ManagerTest $testCase)
    {
        $this->testCase = $testCase;
    }

    public function beforeAction($event, $component, $data)
    {
        $this->testCase->assertInstanceOf(Event::class, $event);
        $this->testCase->assertInstanceOf(ComponentX::class, $component);
        $this->testCase->assertEquals($data, 'extra data');

        $this->before++;
    }

    public function afterAction($event, $component)
    {
        $this->testCase->assertInstanceOf(Event::class, $event);
        $this->testCase->assertInstanceOf(ComponentX::class, $component);
        $this->testCase->assertEquals($event->getData(), ['extra', 'data']);

        $this->after++;

        $this->testCase->setLastListener($this);
    }

    public function getBeforeCount()
    {
        return $this->before;
    }

    public function getAfterCount()
    {
        return $this->after;
    }
}
