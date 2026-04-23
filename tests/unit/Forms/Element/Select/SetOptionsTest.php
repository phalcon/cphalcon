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

use Phalcon\Forms\Element\ElementInterface;
use Phalcon\Forms\Element\Select;
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * Class SetOptionsTest extends AbstractUnitTestCase
 */
final class SetOptionsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsElementSelectSetOptions(): void
    {
        $select  = new Select('status');
        $options = ['1' => 'One', '2' => 'Two'];

        $actual = $select->setOptions($options);
        $this->assertInstanceOf(ElementInterface::class, $actual);

        $this->assertSame($options, $select->getOptions());
    }
}
