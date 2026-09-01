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

namespace Phalcon\Tests\Support\Listener;

use Phalcon\Events\Event;
use Phalcon\Tests\Unit\Mvc\View\Engine\Volt\RenderTest;
use PHPUnit\Framework\Assert;

/**
 * Class ViewCompileListener
 */
class ViewCompileListener
{
    /** @var RenderTest */
    protected $testCase;

    protected $before = '';
    protected $after  = '';

    public function setTestCase(RenderTest $testCase)
    {
        $this->testCase = $testCase;
    }

    /**
     * @param $event
     * @param $component
     */
    public function beforeCompile($event, $component)
    {
        Assert::isInstanceOf(Event::class)->evaluate($event);

        $this->before = 'Before fired';
    }

    /**
     * @param $event
     * @param $component
     */
    public function afterCompile($event, $component)
    {
        Assert::isInstanceOf(Event::class)->evaluate($event);

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
