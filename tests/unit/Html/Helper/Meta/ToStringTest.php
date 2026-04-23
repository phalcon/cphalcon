<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Meta;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Meta;
use Phalcon\Tests\AbstractUnitTestCase;

use const PHP_EOL;

final class ToStringTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlHelperMetaToStringEmpty(): void
    {
        $escaper = new Escaper();
        $helper  = new Meta($escaper);

        $result = $helper();

        $actual = (string)$result;
        $this->assertEmpty($actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16441
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-09-26
     */
    public function testHtmlHelperMetaToStringRetainsValue(): void
    {
        $escaper = new Escaper();
        $meta    = new Meta($escaper);
        $meta
            ->addName('robots', 'index, nofollow')
            ->addName('author', 'Me')
        ;

        $expected = '    <meta name="robots" content="index, nofollow">'
            . PHP_EOL
            . '    <meta name="author" content="Me">'
            . PHP_EOL;
        $actual   = (string)$meta;
        $this->assertSame($expected, $actual);

        $meta = new Meta($escaper);
        $meta->addName('robots', 'index, nofollow');

        $expected = '    <meta name="robots" content="index, nofollow">'
            . PHP_EOL
            . '    <meta name="author" content="Me">'
            . PHP_EOL;
        $actual   = (string)$meta->addName('author', 'Me');
        $this->assertSame($expected, $actual);
    }
}
