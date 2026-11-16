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

namespace Phalcon\Tests\Unit\Html\TagFactory;

use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\WeakTypes\IntTarget;

/**
 * The tag factory calls the helpers with the PHP weak type rules, the same as
 * cphalcon. The test file declares strict_types=1, so the mode of the caller
 * has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testHtmlTagFactoryWeakModeCustomHelper(): void
    {
        $factory = new TagFactory(
            new Escaper(),
            [
                'double' => function (): IntTarget {
                    return new IntTarget();
                },
            ]
        );

        $this->assertSame(10, $factory->double('5'));
    }
}
