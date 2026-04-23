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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\Dynamic;
use Phalcon\Tests\AbstractUnitTestCase;
use RuntimeException;

final class DynamicTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrDynamic(): void
    {
        $object = new Dynamic();
        $actual = $object->__invoke('{Hi|Hello}, my name is Bob!');

        $this->assertStringNotContainsString('{', $actual);
        $this->assertStringNotContainsString('}', $actual);

        $this->assertMatchesRegularExpression(
            '/^(Hi|Hello), my name is Bob!$/',
            $actual,
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrDynamicCustomDelimiter(): void
    {
        $object = new Dynamic();
        $actual = $object->__invoke('(Hi|Hello), my name is Bob!', '(', ')');

        $this->assertStringNotContainsString('{', $actual);
        $this->assertStringNotContainsString('}', $actual);

        $this->assertMatchesRegularExpression(
            '/^(Hi|Hello), my name is Bob!$/',
            $actual,
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrDynamicCustomSeparator(): void
    {
        $object = new Dynamic();
        $actual = $object->__invoke('{Hi=Hello}, my name is Bob!', '{', '}', '=');

        $this->assertStringNotContainsString('{', $actual);
        $this->assertStringNotContainsString('}', $actual);
        $this->assertStringNotContainsString('=', $actual);

        $this->assertMatchesRegularExpression(
            '/^(Hi|Hello), my name is Bob!$/',
            $actual,
        );

        $actual = $object->__invoke("{Hi'Hello}, my name is {Rob'Zyxep'Andres}!", '{', '}', "'");

        $this->assertStringNotContainsString('{', $actual);
        $this->assertStringNotContainsString('}', $actual);
        $this->assertStringNotContainsString("''", $actual);

        $this->assertMatchesRegularExpression(
            '/^(Hi|Hello), my name is (Rob|Zyxep|Andres)!$/',
            $actual,
        );

        $actual = $object->__invoke('{Hi/Hello}, my name is {Stanislav/Nikos}!', '{', '}', '/');

        $this->assertStringNotContainsString('{', $actual);
        $this->assertStringNotContainsString('}', $actual);
        $this->assertStringNotContainsString('/', $actual);

        $this->assertMatchesRegularExpression(
            '/^(Hi|Hello), my name is (Stanislav|Nikos)!$/',
            $actual,
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrDynamicException(): void
    {
        $this->expectException(RuntimeException::class);
        $this->expectExceptionMessage(
            "Syntax error in string '{{Hi/Hello}'",
        );
        $object = new Dynamic();
        $object->__invoke('{{Hi/Hello}');
    }
}
