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
use stdClass;
use TypeError;

final class UnderscoreCallTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterTagFactoryUnderscoreCall(): void
    {
        $escaper = new Escaper();
        $factory = new TagFactory($escaper);

        $expected = '<body>';
        $actual   = $factory->body();
        $this->assertSame($expected, $actual);
    }

    /**
     * A helper with no __invoke() throws the TypeError of
     * call_user_func_array().
     *
     * @issue  https://github.com/phalcon/phalcon/issues/808
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-15
     */
    public function testHtmlTagFactoryUnderscoreCallNotCallable(): void
    {
        $factory = new TagFactory(
            new Escaper(),
            [
                'custom' => static fn () => new stdClass(),
            ]
        );

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'class stdClass does not have a method "__invoke"'
        );

        $factory->custom('5');
    }
}
