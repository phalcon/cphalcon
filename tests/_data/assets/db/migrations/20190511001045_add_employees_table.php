<?php

use Phinx\Migration\AbstractMigration;

class AddEmployeesTable extends AbstractMigration
{
    public function up()
    {
        $table = $this->table(
            'co_employees',
            [
                'id'     => 'empId',
                'signed' => false,
            ]
        );
        $table
            ->addColumn(
                'empNameFirst',
                'string',
                [
                    'limit'   => 64,
                    'null'    => false,
                    'default' => '',
                ]
            )
            ->addColumn(
                'empNameLast',
                'string',
                [
                    'limit'   => 128,
                    'null'    => false,
                    'default' => '',
                ]
            )
            ->addColumn(
                'empCreatedDate',
                'datetime',
                [
                    'null' => true,
                ]
            )
            ->addColumn(
                'empCreatedEmpId',
                'integer',
                [
                    'limit'   => 11,
                    'null'    => false,
                    'signed'  => false,
                    'default' => 0,
                ]
            )
            ->addIndex('empNameFirst')
            ->addIndex('empNameLast')
            ->addIndex('empCreatedDate')
            ->addIndex('empCreatedEmpId')
            ->save();
    }

    public function down()
    {
        $this->table('co_employees')->drop()->save();
    }
}
