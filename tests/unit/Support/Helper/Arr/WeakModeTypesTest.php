<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Helper\Arr;

use Phalcon\Support\Helper\Arr\Group;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

/**
 * The Group helper calls the callable with the PHP weak type rules, the same
 * as cphalcon. The test file declares strict_types=1, so the mode of the
 * caller has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testSupportHelperArrGroupWeakMode(): void
    {
        $actual = (new Group())(
            ['5'],
            function (int $value): string {
                return 'k';
            }
        );

        $this->assertSame(['k' => ['5']], $actual);
    }
}
