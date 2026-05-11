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

namespace Phalcon\Tests\Unit\Forms\Form;

use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Exception;
use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

/**
 * Class BindTest extends AbstractUnitTestCase
 */
final class BindTest extends AbstractUnitTestCase
{
    public function testBindWhitelist(): void
    {
        $form = new Form();
        $form->add(new Text('nameFirst'));
        $form->add(new Text('nameLast'));

        $data = [
            'test1'     => 'test1',
            'nameFirst' => 'nameFirst',
            'nameLast'  => 'nameLast',
        ];

        $entity    = new stdClass();
        $whiteList = ['nameFirst', 'nameLast'];
        $form->bind($data, $entity, $whiteList);

        $this->assertEquals("nameFirst", $form->getValue("nameFirst"));
        $this->assertEquals("nameLast", $form->getValue("nameLast"));
        $this->assertNull($form->getValue("test1"));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsFormBind(): void
    {
        $form = new Form();
        $form->add(new Text('test1'));

        $data = [
            'test1' => 'test1',
        ];

        $form->bind($data, new stdClass());

        $this->assertEquals("test1", $form->getValue("test1"));
    }

    /**
     * Issue #15957 - Radio elements registered under distinct form-element
     * identifiers but sharing the same HTML "name" attribute must bind to
     * the entity using the HTML name as the property key.
     */
    public function testFormsFormBindRadioWithSharedHtmlName(): void
    {
        $form = new Form();
        $form->add(new Radio('r0', ['name' => 'banned', 'value' => 'no']));
        $form->add(new Radio('r1', ['name' => 'banned', 'value' => 'yes']));

        $entity = new stdClass();
        $form->bind(['banned' => 'yes'], $entity);

        $this->assertEquals('yes', $entity->banned);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsFormBindNoElementsThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('There are no elements in the form');

        $form = new Form();
        $form->bind(['key' => 'value']);
    }
}
