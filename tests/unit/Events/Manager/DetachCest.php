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

namespace Phalcon\Tests\Unit\Events\Manager;

use Codeception\Example;
use Phalcon\Events\Manager;
use stdClass;
use UnitTester;

class DetachCest
{
    /**
     * Tests detach handler by using an Object
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12882
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-06-06
     *
     * @dataProvider booleanProvider
     */
    public function detachObjectListener(UnitTester $I, Example $example)
    {
        $enablePriorities = $example[0];


        $manager = new Manager();

        $manager->enablePriorities($enablePriorities);

        $handler = new stdClass();

        $manager->attach('test:detachable', $handler);

        $events = $I->getProtectedProperty($manager, 'events');

        $I->assertCount(1, $events);

        $I->assertArrayHasKey('test:detachable', $events);

        $I->assertCount(
            1,
            $events['test:detachable']
        );

        $manager->detach('test:detachable', $handler);

        $events = $I->getProtectedProperty($manager, 'events');

        $I->assertCount(1, $events);

        $I->assertArrayHasKey('test:detachable', $events);

        $I->assertCount(
            0,
            $events['test:detachable']
        );
    }

    private function booleanProvider(): array
    {
        return [
            [true],
            [false],
        ];
    }
}
