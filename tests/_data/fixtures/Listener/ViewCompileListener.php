<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Fixtures\Listener;

use IntegrationTester;
use Phalcon\Events\Event;
use Phalcon\Tests\Integration\Mvc\View\Engine\Volt\RenderCest;
use UnitTester;

/**
 * Class ViewCompileListener
 */
class ViewCompileListener
{
    /** @var RenderCest */
    protected $testCase;

    /** @var UnitTester */
    protected $tester;

    protected $before = '';
    protected $after  = '';

    public function setTestCase(RenderCest $testCase, IntegrationTester $tester)
    {
        $this->testCase = $testCase;
        $this->tester   = $tester;
    }

    /**
     * @param $event
     * @param $component
     */
    public function beforeCompile($event, $component)
    {
        $this->tester->assertInstanceOf(
            Event::class,
            $event
        );

        $this->before = 'Before fired';
    }

    /**
     * @param $event
     * @param $component
     */
    public function afterCompile($event, $component)
    {
        $this->tester->assertInstanceOf(
            Event::class,
            $event
        );

        $this->after = 'After fired';
    }

    public function getAfter(): string
    {
        return $this->after;
    }

    public function getBefore(): string
    {
        return $this->before;
    }
}
