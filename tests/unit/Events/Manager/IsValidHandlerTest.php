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

use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractUnitTestCase;

final class IsValidHandlerTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        $objectHandler  = new Manager();
        $closureHandler = function () {
            return true;
        };

        return [
            [
                false,
                'handler',
            ],
            [
                false,
                134,
            ],
            [
                true,
                $objectHandler,
            ],
            [
                true,
                [$objectHandler, 'hasListeners'],
            ],
            [
                true,
                $closureHandler,
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEventsManagerIsValidHandler(
        bool $expected,
        mixed $handler
    ): void {
        $manager = new Manager();

        $actual = $manager->isValidHandler($handler);
        $this->assertSame($expected, $actual);
    }
}
