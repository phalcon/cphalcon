<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Forms\Element;

use Phalcon\Forms\Element\AbstractElement;
use Phalcon\Forms\Element\ElementInterface;
use Phalcon\Forms\Form;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Forms\Fake\FormsTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use ReflectionMethod;

use function uniqid;

final class GetSetFormTest extends AbstractUnitTestCase
{
    use FormsTrait;

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    #[DataProvider('getExamples')]
    public function testFormsElementGetFormAdd(
        string $class
    ): void {
        $name   = uniqid();
        $object = new $class($name);
        $form   = new Form();

        $object->setForm($form);

        $expected = $form;
        $actual   = $object->getForm();
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17781
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-24
     */
    #[DataProvider('getExamples')]
    public function testFormsElementGetFormNotSet(
        string $class
    ): void {
        $object = new $class(uniqid());

        $this->assertNull($object->getForm());
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17781
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-24
     */
    public function testFormsElementGetFormReturnType(): void
    {
        $element   = new ReflectionMethod(AbstractElement::class, 'getForm');
        $interface = new ReflectionMethod(ElementInterface::class, 'getForm');

        $this->assertSame('?Phalcon\Forms\Form', (string) $element->getReturnType());
        $this->assertSame('?Phalcon\Forms\Form', (string) $interface->getReturnType());
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    #[DataProvider('getExamples')]
    public function testFormsElementGetSetForm(
        string $class
    ): void {
        $name   = uniqid();
        $object = new $class($name);
        $form   = new Form();

        $object->setForm($form);

        $expected = $form;
        $actual   = $object->getForm();
        $this->assertSame($expected, $actual);
    }
}
