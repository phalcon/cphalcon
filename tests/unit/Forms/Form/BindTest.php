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

use Phalcon\Forms\Element\Check;
use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Exception;
use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Forms\Fake\FakeFormAfterBind;
use Phalcon\Tests\Unit\Forms\Fake\FakeFormBeforeBind;
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
     * Tests that the afterBind() hook is invoked after bind() assigns data.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/14598
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-05
     */
    public function testFormsFormBindAfterBindCalled(): void
    {
        $form = new FakeFormAfterBind();
        $form->add(new Text('name'));

        $form->bind(['name' => 'test'], new stdClass());

        $this->assertTrue($form->afterBindCalled);
    }

    /**
     * Tests that returning false from beforeBind() cancels the bind so the
     * entity is left untouched.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/14598
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-05
     */
    public function testFormsFormBindBeforeBindReturnsFalseAbortsBind(): void
    {
        $form = new FakeFormBeforeBind();
        $form->add(new Text('name'));

        $entity       = new stdClass();
        $entity->name = 'original';
        $form->bind(['name' => 'changed'], $entity);

        $this->assertSame('original', $entity->name);
    }

    /**
     * Issue #16982 - When the checkbox IS submitted, the explicit POST value
     * must win over the registered unchecked value.
     */
    public function testFormsFormBindCheckboxExplicitValueWinsOverUncheckedDefault(): void
    {
        $form = new Form();
        $form->add((new Check('ours'))->setUncheckedValue(0));

        $entity = new stdClass();
        $form->bind(['ours' => 'on'], $entity);

        $this->assertSame('on', $entity->ours);
    }

    /**
     * Issue #16982 - Unchecked checkboxes are absent from POST data so the
     * entity property is never reset. When a Check element has an explicit
     * "unchecked value" registered, bind() must apply it.
     */
    public function testFormsFormBindCheckboxUncheckedAppliesDefault(): void
    {
        $form = new Form();
        $form->add((new Check('ours'))->setUncheckedValue(0));

        $entity = new stdClass();
        $entity->ours = 1;
        $form->bind([], $entity);

        $this->assertSame(0, $entity->ours);
    }

    /**
     * Issue #16982 - Without setUncheckedValue(), bind() must preserve the
     * pre-existing behavior and leave the entity property untouched.
     */
    public function testFormsFormBindCheckboxWithoutUncheckedValueLeavesEntityAlone(): void
    {
        $form = new Form();
        $form->add(new Check('ours'));

        $entity = new stdClass();
        $entity->ours = 1;
        $form->bind([], $entity);

        $this->assertSame(1, $entity->ours);
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
}
