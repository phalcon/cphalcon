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

namespace Phalcon\Tests\Unit\Dispatcher;

use Phalcon\Mvc\Dispatcher;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetActiveMethodTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                'actionName' => 'hello-phalcon',
                'expected'   => 'helloPhalconAction',
            ],

            [
                'actionName' => 'home_page',
                'expected'   => 'homePageAction',
            ],

            [
                'actionName' => 'secondPage',
                'expected'   => 'secondPageAction',
            ],

            [
                'actionName' => 'ThirdPage',
                'expected'   => 'thirdPageAction',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDispatcherGetActiveMethod(
        string $actionName,
        string $expected
    ): void {
        $dispatcher = new Dispatcher();
        $dispatcher->setActionSuffix('Action');


        $dispatcher->setActionName($actionName);

        $actual = $dispatcher->getActiveMethod();
        $this->assertSame($expected, $actual);
    }
}
