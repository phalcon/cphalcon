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

namespace Phalcon\Tests\Database\Mvc\Model;

use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\FractalDatesMigration;
use Phalcon\Tests\Support\Models\FractalDates;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class UpdateFunctionDefaultTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getConnection();
        (new FractalDatesMigration($connection));
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() - column with function-call DB default
     * is not passed as string on subsequent UPDATE
     *
     * @see    https://github.com/phalcon/cphalcon/issues/15828
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    #[Group('pgsql')]
    public function testMvcModelUpdateWithFunctionCallDefault(): void
    {
        /**
         * With orm.dynamic_update ON (default), snapshots mask the bug because
         * cuuid appears unchanged (snapshot value == model value). Disable it
         * so the non-dynamic update path is exercised and we confirm the string
         * 'gen_random_uuid()' is NOT passed as a bound parameter.
         */
        $previous = Settings::get('orm.dynamic_update');
        Settings::set('orm.dynamic_update', false);

        try {
            $model        = new FractalDates();
            $model->ftime = '12:00:00';

            $this->assertTrue($model->save(), implode(' ', $model->getMessages()));

            $model->ftime = '13:00:00';

            $this->assertTrue($model->save(), implode(' ', $model->getMessages()));
        } finally {
            Settings::set('orm.dynamic_update', $previous);
        }
    }
}
