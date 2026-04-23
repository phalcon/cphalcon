<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Unit\Forms\Form;

use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class IteratorTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    public function testIterator(): void
    {
        $form = new Form();
        $data = [];

        foreach ($form as $key => $value) {
            $data[$key] = $value->getName();
        }

        $this->assertEquals(
            [],
            $data
        );


        $form->add(
            new Text('name')
        );

        $form->add(
            new Text('telephone')
        );

        foreach ($form as $key => $value) {
            $data[$key] = $value->getName();
        }

        $expected = [
            0 => 'name',
            1 => 'telephone',
        ];

        $this->assertEquals($expected, $data);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsFormCurrentReturnsFalseWhenOutOfBounds(): void
    {
        $form = new Form();
        $form->add(new Text('name'));
        $form->rewind();

        // Advance beyond end
        $form->next();

        $actual = $form->current();
        $this->assertFalse($actual);
    }
}
