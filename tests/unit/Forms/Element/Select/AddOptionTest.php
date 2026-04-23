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

namespace Phalcon\Tests\Unit\Forms\Element\Select;

use Phalcon\Forms\Element\Select;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function preg_replace;

final class AddOptionTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-17
     */
    public function testFormsElementSelectAddOptionArray(): void
    {
        $element = new Select('test-select');
        $element->setTagFactory(new TagFactory(new Escaper()));
        $element->addOption(
            [
                'key' => 'value',
            ]
        );

        $expected = '<select id="test-select" name="test-select"><option value="key">value</option></select>';
        $actual   = preg_replace('/[[:cntrl:]]/', '', $element->render());
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-17
     */
    public function testFormsElementSelectAddOptionString(): void
    {
        $element = new Select('test-select');
        $element->setTagFactory(new TagFactory(new Escaper()));

        $element->addOption('value');

        $expected = '<select id="test-select" name="test-select"><option value="0">value</option></select>';
        $actual   = preg_replace('/[[:cntrl:]]/', '', $element->render());
        $this->assertSame($expected, $actual);
    }
}
