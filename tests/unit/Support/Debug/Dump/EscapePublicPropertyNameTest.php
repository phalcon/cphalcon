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

namespace Phalcon\Tests\Unit\Support\Debug\Dump;

use Phalcon\Support\Debug\Dump;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use stdClass;

final class EscapePublicPropertyNameTest extends AbstractUnitTestCase
{
    /**
     * A dumped public property name must be escaped.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17729
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-06
     */
    public function testDumpEscapesPublicPropertyName(): void
    {
        $object = new stdClass();
        $object->{'<img src=x onerror=alert(1)>'} = 'value';

        $html = (new Dump())->variable($object);

        $this->assertStringNotContainsString(
            '<img src=x onerror=alert(1)>',
            $html
        );
        $this->assertStringContainsString(
            '&lt;img src=x onerror=alert(1)&gt;',
            $html
        );
    }

    /**
     * A dumped public property name must be escaped in detailed mode.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17729
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-06
     */
    public function testDumpEscapesPublicPropertyNameDetailed(): void
    {
        $object = new stdClass();
        $object->{'<img src=x onerror=alert(1)>'} = 'value';

        $html = (new Dump([], true))->variable($object);

        $this->assertStringNotContainsString(
            '<img src=x onerror=alert(1)>',
            $html
        );
        $this->assertStringContainsString(
            '&lt;img src=x onerror=alert(1)&gt;',
            $html
        );
    }
}
