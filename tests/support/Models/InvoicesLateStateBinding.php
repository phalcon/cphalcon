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

namespace Phalcon\Tests\Support\Models;

use Phalcon\Mvc\ModelInterface;

/**
 * A model with its own cloneResultMap(). With late state binding on, a
 * resultset hydrates its rows with this method, and each model has
 * lateStateBound set to true.
 */
class InvoicesLateStateBinding extends Invoices
{
    public bool $lateStateBound = false;

    public static function cloneResultMap(
        $base,
        array $data,
        $columnMap,
        int $dirtyState = 0,
        ?bool $keepSnapshots = null
    ): ModelInterface {
        /** @var InvoicesLateStateBinding $model */
        $model = parent::cloneResultMap(
            $base,
            $data,
            $columnMap,
            $dirtyState,
            $keepSnapshots
        );

        $model->lateStateBound = true;

        return $model;
    }
}
