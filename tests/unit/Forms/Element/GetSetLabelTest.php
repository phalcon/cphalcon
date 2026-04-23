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

use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Forms\Fake\FormsTrait;

use function uniqid;

final class GetSetLabelTest extends AbstractUnitTestCase
{
    use FormsTrait;

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function testFormsElementGetSetLabel(
        string $class
    ): void {
        $name    = uniqid();
        $factory = new TagFactory(new Escaper());
        $object  = new $class($name);
        $object->setTagFactory($factory);

        $actual = $object->getLabel();
        $this->assertNull($actual);

        $object->setLabel($name);

        $expected = $name;
        $actual   = $object->getLabel();
        $this->assertSame($expected, $actual);

        $attributes = ['class' => 'label label-warning'];
        $expected   = '<label for="' . $name
            . '" class="label label-warning">' . $name . '</label>';
        $actual     = $object->label($attributes);
        $this->assertSame($expected, $actual);
    }
}
