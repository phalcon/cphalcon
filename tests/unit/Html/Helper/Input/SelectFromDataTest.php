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

namespace Phalcon\Tests\Unit\Html\Helper\Input;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Input\Select;
use Phalcon\Html\Helper\Input\Select\ArrayData;
use Phalcon\Tests\AbstractUnitTestCase;

use const PHP_EOL;

final class SelectFromDataTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testFromDataRendersFlatOptions(): void
    {
        $escaper = new Escaper();
        $helper  = new Select($escaper);
        $result  = $helper('    ', PHP_EOL, ['id' => 'cars']);
        $result->fromData(new ArrayData(['1' => 'Ferrari', '2' => 'Ford']));

        $expected = '<select id="cars">' . PHP_EOL
            . '    <option value="1">Ferrari</option>' . PHP_EOL
            . '    <option value="2">Ford</option>' . PHP_EOL
            . '</select>';

        $this->assertSame($expected, (string) $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testFromDataRendersOptgroups(): void
    {
        $escaper = new Escaper();
        $helper  = new Select($escaper);
        $result  = $helper('    ', PHP_EOL, ['id' => 'cars']);
        $result->fromData(new ArrayData([
            'Italian'  => ['1' => 'Ferrari'],
            'American' => ['2' => 'Ford'],
        ]));

        $expected = '<select id="cars">' . PHP_EOL
            . '    <optgroup label="Italian">' . PHP_EOL
            . '        <option value="1">Ferrari</option>' . PHP_EOL
            . '    </optgroup>' . PHP_EOL
            . '    <optgroup label="American">' . PHP_EOL
            . '        <option value="2">Ford</option>' . PHP_EOL
            . '    </optgroup>' . PHP_EOL
            . '</select>';

        $this->assertSame($expected, (string) $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testFromDataRespectsSelectedValue(): void
    {
        $escaper = new Escaper();
        $helper  = new Select($escaper);
        $result  = $helper('    ', PHP_EOL, ['id' => 'cars']);
        $result->selected('2');
        $result->fromData(new ArrayData(['1' => 'Ferrari', '2' => 'Ford']));

        $actual = (string) $result;

        $this->assertStringContainsString('selected="selected"', $actual);
        $this->assertStringContainsString('value="2"', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testFromDataWithEmptyArrayRendersEmptySelect(): void
    {
        $escaper = new Escaper();
        $helper  = new Select($escaper);
        $result  = $helper('    ', PHP_EOL, ['id' => 'cars']);
        $result->fromData(new ArrayData([]));

        $this->assertSame('', (string) $result);
    }
}
