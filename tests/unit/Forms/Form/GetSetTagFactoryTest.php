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

use Phalcon\Forms\Form;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetTagFactoryTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-30
     */
    public function testFormsFormGetSetTagFactory(): void
    {
        $escaper       = new Escaper();
        $tagFactoryOne = new TagFactory($escaper);

        $form = new Form();

        /**
         * Initial
         */
        $actual = $form->getTagFactory();
        $this->assertNull($actual);

        $form->setTagFactory($tagFactoryOne);

        $expected = $tagFactoryOne;
        $actual   = $form->getTagFactory();
        $this->assertSame($expected, $actual);
    }
}
