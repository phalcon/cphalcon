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

use Phalcon\Mvc\Model;

/**
 * Accounting model whose metadata comes from column annotations (used by the
 * MetaData Annotations-strategy tests).
 */
class InvoicesAnnotated extends Model
{
    /**
     * @Primary
     * @Identity
     * @Column(type="integer", nullable=false)
     */
    public $inv_id;

    /**
     * @Column(type="integer", nullable=false)
     */
    public $inv_cst_id;

    /**
     * @Column(type="integer", nullable=false)
     */
    public $inv_status_flag;

    /**
     * @Column(type="string", length=100, nullable=false)
     */
    public $inv_title;

    /**
     * @Column(type="float", nullable=false)
     */
    public $inv_total;

    /**
     * @Column(type="datetime", nullable=false)
     */
    public $inv_created_at;
}
