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
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Meta;
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
                '    ',
                PHP_EOL,
                [
                    "charset" => 'utf-8',
                ],
                [
                    "X-UA-Compatible",
                    "IE=edge",
                ],
                [
                    "generator",
                    "Phalcon",
                ],
                [
                    "org:url",
                    "https://phalcon.io",
                ],
                "    <meta charset=\"utf-8\">" . PHP_EOL
                . "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">" . PHP_EOL
                . "    <meta name=\"generator\" content=\"Phalcon\">" . PHP_EOL
                . "    <meta property=\"org:url\" content=\"https://phalcon.io\">" . PHP_EOL,
            ],
            [
                '--',
                '+',
                [
                    "charset" => 'utf-8',
                ],
                [
                    "X-UA-Compatible",
                    "IE=edge",
                ],
                [
                    "generator",
                    "Phalcon",
                ],
                [
                    "org:url",
                    "https://phalcon.io",
                ],
                "--<meta charset=\"utf-8\">+"
                . "--<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">+"
                . "--<meta name=\"generator\" content=\"Phalcon\">+"
                . "--<meta property=\"org:url\" content=\"https://phalcon.io\">+",
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testHtmlHelperMetaUnderscoreInvoke(
        string $indent,
        string $delimiter,
        array $add,
        array $http,
        array $name,
        array $property,
        string $expected
    ): void {
        $escaper = new Escaper();
        $helper  = new Meta($escaper);

        $result = $helper($indent, $delimiter)
            ->add($add)
            ->addHttp($http[0], $http[1])
            ->addName($name[0], $name[1])
            ->addProperty($property[0], $property[1])
        ;

        $actual = (string)$result;
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('meta');
        $result  = $locator($indent, $delimiter)
            ->add($add)
            ->addHttp($http[0], $http[1])
            ->addName($name[0], $name[1])
            ->addProperty($property[0], $property[1])
        ;

        $actual = (string)$result;
        $this->assertSame($expected, $actual);
    }
}
