<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Listener;

use Phalcon\Events\Event;
use Phalcon\Test\Fixtures\Events\ComponentX;
use Phalcon\Test\Unit\Events\ManagerCest;
use UnitTester;

class ThirdListener
{
    /** @var ManagerCest */
    protected $testCase;

    /** @var UnitTester */
    protected $tester;

    protected $before = 0;

    protected $after = 0;

    public function setTestCase(ManagerCest $testCase, UnitTester $tester)
    {
        $this->testCase = $testCase;
        $this->tester   = $tester;
    }

    public function beforeAction($event, $component, $data)
    {
        $this->tester->assertInstanceOf(
            Event::class,
            $event
        );

        $this->tester->assertInstanceOf(
            ComponentX::class,
            $component
        );

        $this->tester->assertEquals(
            'extra data',
            $data
        );

        $this->before++;
    }

    public function afterAction($event, $component)
    {
        $this->tester->assertInstanceOf(
            Event::class,
            $event
        );

        $this->tester->assertInstanceOf(
            ComponentX::class,
            $component
        );

        $this->tester->assertEquals(
            ['extra', 'data'],
            $event->getData()
        );

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
