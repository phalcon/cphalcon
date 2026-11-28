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

use Phalcon\Forms\Form;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DebugBuildTrait;
use Phalcon\Tests\Unit\Forms\Fake\FormsTrait;
use PHPUnit\Framework\Attributes\DataProvider;

use function uniqid;

final class GetSetFormTest extends AbstractUnitTestCase
{
    use DebugBuildTrait;
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
        $this->skipOnDebugBuild();

        $object = new $class(uniqid());

        $this->assertNull($object->getForm());
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
