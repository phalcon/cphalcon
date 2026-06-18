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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt\Compiler;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

class AddFilterTest extends AbstractUnitTestCase
{
    public static function getVoltAddFilter(): array
    {
        return [
            [
                'reverse',
                'strrev',
                '{{ "hello"|reverse }}',
                '<?= strrev(\'hello\') ?>',
            ],
        ];
    }

    public static function getVoltAddFilterClosure(): array
    {
        return [
            [
                'separate',
                'explode',
                '{{ "1,2,3,4"|separate }}',
                '<?= explode(",", \'1,2,3,4\') ?>',
            ],
        ];
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    #[DataProvider('getVoltAddFilter')]
    public function testMvcViewEngineVoltCompilerAddFilter(
        string $name,
        string $filter,
        string $voltName,
        string $expected
    ): void {
        $volt = new Compiler();

        $volt->addFilter($name, $filter);

        $actual = $volt->compileString($voltName);

        $this->assertEquals($expected, $actual);
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    #[DataProvider('getVoltAddFilterClosure')]
    public function testMvcViewEngineVoltCompilerAddFilterClosure(
        string $name,
        string $filter,
        string $voltName,
        string $expected
    ): void {
        $volt = new Compiler();

        $volt->addFilter(
            $name,
            function ($arguments) use ($filter) {
                return $filter . '(",", ' . $arguments . ')';
            }
        );

        $this->assertEquals(
            $expected,
            $volt->compileString($voltName)
        );
    }
}
