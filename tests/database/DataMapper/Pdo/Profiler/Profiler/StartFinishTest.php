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

namespace Phalcon\Tests\Database\DataMapper\Pdo\Profiler\Profiler;

use Phalcon\DataMapper\Pdo\Profiler\Profiler;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

use function sleep;
use function strpos;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class StartFinishTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoProfilerProfilerStartFinish(): void
    {
        $profiler = new Profiler();

        $profiler
            ->setActive(true)
            ->start('my-method')
        ;

        sleep(1);
        $profiler->finish('select from something', [1 => 2]);

        $logger  = $profiler->getLogger();
        $message = $logger->getMessages()[0];

        $this->assertNotFalse(strpos($message, 'my-method ('));
        $this->assertNotFalse(strpos($message, 'select from something #0'));
    }
}
