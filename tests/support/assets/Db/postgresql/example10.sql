CREATE TABLE "table" (
	"column14" SERIAL NOT NULL,
	"column15" INT DEFAULT 5 NOT NULL,
	"column16" CHARACTER VARYING(10) DEFAULT 'column16',
	"column17" BOOLEAN DEFAULT false NOT NULL,
	"column18" BOOLEAN DEFAULT true NOT NULL
);
COMMENT ON COLUMN "table"."column14" IS 'test';
COMMENT ON COLUMN "table"."column15" IS 'test';
COMMENT ON COLUMN "table"."column16" IS 'test';
COMMENT ON COLUMN "table"."column17" IS 'test';
COMMENT ON COLUMN "table"."column18" IS 'test';

