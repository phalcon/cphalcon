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

class InvoicesSkipCreateExtended extends InvoicesSkipCreate
{
    public $cst_id;
    public $cst_status_flag;
    public $cst_name_last;
    public $cst_name_first;

    public function initialize()
    {
        parent::initialize();

        $this->setSource('co_customers');
    }
}
