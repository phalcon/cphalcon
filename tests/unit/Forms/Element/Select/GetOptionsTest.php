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
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * Class GetOptionsTest extends AbstractUnitTestCase
 */
final class GetOptionsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsElementSelectGetOptions(): void
    {
        $options = ['1' => 'One', '2' => 'Two'];
        $select  = new Select('status', $options);

        $actual = $select->getOptions();
        $this->assertSame($options, $actual);
    }
}
