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

namespace Phalcon\Tests\Database\Mvc\Model\Behavior\SoftDelete;

use Phalcon\Mvc\Model\Behavior;
use Phalcon\Mvc\Model\Behavior\SoftDelete;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ConstructTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelBehaviorSoftdeleteConstruct(): void
    {
        $behavior = new SoftDelete(
            [
                'field' => 'inv_status_flag',
                'value' => 0,
            ]
        );

        $this->assertInstanceOf(SoftDelete::class, $behavior);
        $this->assertInstanceOf(Behavior::class, $behavior);

        $options = $this->invokeMethod($behavior, 'getOptions');

        $this->assertSame(
            [
                'field' => 'inv_status_flag',
                'value' => 0,
            ],
            $options
        );
    }
}
