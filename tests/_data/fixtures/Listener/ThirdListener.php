<?php
declare(strict_types=1);

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
use function dataFolder;
use Phalcon\Events\Event;
use Phalcon\Test\Unit\Events\ManagerCest;
use UnitTester;

class ThirdListener
{
    /** @var  ManagerCest */
    protected $testCase;

    /** @var  UnitTester */
    protected $tester;

    protected $before = 0;

    protected $after = 0;

    public function __construct()
    {
        include_once dataFolder('fixtures/Events/ComponentX.php');
    }

    public function setTestCase(ManagerCest $testCase, UnitTester $tester)
    {
        $this->testCase = $testCase;
        $this->tester   = $tester;
    }

    public function beforeAction($event, $component, $data)
    {
        $this->tester->assertInstanceOf(Event::class, $event);
        $this->tester->assertInstanceOf(ComponentX::class, $component);
        $this->tester->assertEquals($data, 'extra data');

        $this->before++;
    }

    public function afterAction($event, $component)
    {
        $this->tester->assertInstanceOf(Event::class, $event);
        $this->tester->assertInstanceOf(ComponentX::class, $component);
        $this->tester->assertEquals($event->getData(), ['extra', 'data']);

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
