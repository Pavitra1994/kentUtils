# pgPolyphenPred.sql was originally generated by the autoSql program, which also 
# generated pgPolyphenPred.c and pgPolyphenPred.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#polyphen predictions for pgSnp tracks
CREATE TABLE pgPolyphenPred (
    chrom varchar(255),	# Chromosome
    chromStart int unsigned,	# Start position in chrom
    chromEnd int unsigned,	# End position in chrom
    prediction varchar(255),	# polyphens prediction, damaging, benign,...
    basedOn varchar(255),	# prediction basis
    geneName varchar(255),	# gene/protein name
    aaChange varchar(255),	# amino acid change
              #Indices
    INDEX(chrom(20), chromStart)
);