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

namespace Phalcon\Tests\Unit\Forms\Element;

use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Forms\Fake\FormsTrait;
use PHPUnit\Framework\Attributes\DataProvider;

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
