<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Doctype;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Doctype;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

use const PHP_EOL;

final class UnderscoreInvokeTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamples(): array
    {
        return [
            [
                Doctype::HTML32,
                PHP_EOL,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">"
                . PHP_EOL,
            ],
            [
                Doctype::HTML401_STRICT,
                PHP_EOL,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/html4/strict.dtd\">"
                . PHP_EOL,
            ],
            [
                Doctype::HTML401_TRANSITIONAL,
                PHP_EOL,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/html4/loose.dtd\">"
                . PHP_EOL,
            ],
            [
                Doctype::HTML401_FRAMESET,
                PHP_EOL,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/html4/frameset.dtd\">"
                . PHP_EOL,
            ],
            [
                Doctype::XHTML10_STRICT,
                PHP_EOL,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">"
                . PHP_EOL,
            ],
            [
                Doctype::XHTML10_TRANSITIONAL,
                PHP_EOL,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">"
                . PHP_EOL,
            ],
            [
                Doctype::XHTML10_FRAMESET,
                PHP_EOL,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">"
                . PHP_EOL,
            ],
            [
                Doctype::XHTML11,
                PHP_EOL,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">"
                . PHP_EOL,
            ],
            [
                Doctype::XHTML20,
                PHP_EOL,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">"
                . PHP_EOL,
            ],
            [
                Doctype::HTML5,
                PHP_EOL,
                "<!DOCTYPE html>" . PHP_EOL,
            ],
            [
                Doctype::XHTML5,
                PHP_EOL,
                "<!DOCTYPE html>" . PHP_EOL,
            ],
            [
                100,
                PHP_EOL,
                "<!DOCTYPE html>" . PHP_EOL,
            ],
            [
                Doctype::XHTML11,
                '-:-',
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\""
                . '-:-'
                . "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">"
                . '-:-',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testHtmlHelperDoctypeUnderscoreInvoke(
        int $flag,
        string $delimiter,
        string $expected
    ): void {
        $helper = new Doctype();
        $helper->__invoke($flag, $delimiter);
        $actual = (string)$helper;
        $this->assertSame($expected, $actual);

        $escaper = new Escaper();
        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('doctype');

        $actual = (string)$locator($flag, $delimiter);
        $this->assertSame($expected, $actual);
    }
}
