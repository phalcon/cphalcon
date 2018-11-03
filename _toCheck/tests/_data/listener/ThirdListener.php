<?php

namespace Phalcon\Test\Listener;

use ComponentX;
use Phalcon\Events\Event;
use Phalcon\Test\Unit\Events\ManagerTest;

/**
 * Phalcon\Test\Listener\ThirdListener
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Listener
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
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
